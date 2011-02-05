/***************************************************************************
 *   Copyright (C) 2010-2011 Kai Heitkamp                                  *
 *   dynup@ymail.com | wiibafu.codeplex.com                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <QtGui/QApplication>
#include "wiibafu.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QCoreApplication::setOrganizationDomain("wiibafu.codeplex.com");
    QCoreApplication::setOrganizationName("Kai Heitkamp");
    QCoreApplication::setApplicationName("Wii Backup Fusion");
    QCoreApplication::setApplicationVersion("1.1");

    QTranslator qtTranslator, appTranslator;
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));
    qtTranslator.load(QString(":locale/qt_%1.qm").arg(QLocale::system().name()));
    appTranslator.load(QString(":locale/%1.qm").arg(QLocale::system().languageToString(QLocale::system().language()).toLower()));

    app.installTranslator(&qtTranslator);
    app.installTranslator(&appTranslator);

    WiiBaFu wiibafu;
    wiibafu.show();

    return app.exec();
}
