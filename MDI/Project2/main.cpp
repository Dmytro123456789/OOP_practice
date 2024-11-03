#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>

QFile logFile;

void messageHandler(QtMsgType type, const QMessageLogContext&, const QString& msg) {
    if (logFile.isOpen()) {
        QTextStream out(&logFile);
        switch (type) {
        case QtDebugMsg:
            out << "Debug: " << msg << "\n";
            break;
        case QtWarningMsg:
            out << "Warning: " << msg << "\n";
            break;
        case QtCriticalMsg:
            out << "Critical: " << msg << "\n";
            break;
        case QtFatalMsg:
            out << "Fatal: " << msg << "\n";
            abort();
        case QtInfoMsg:
            break;
        }
        out.flush();
    }
}

void setupLogging() {
    logFile.setFileName("logfile.txt");
    if (!logFile.open(QIODevice::WriteOnly | QIODevice::Append)) {
        qDebug() << "Не вдалося відкрити лог-файл";
    }
    else {
        qInstallMessageHandler(messageHandler);
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
