/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2018  Πέτρος Σιλιγκούνας <petross404@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "about.h"

About::About(QWidget* parent) : QDialog(parent)
{
	QGridLayout* gl = new QGridLayout;
	label = new QLabel(tr("Hi there"), this);
	gl->addWidget(label, 0, 0);
	setLayout(gl);
}

About::~About()
{
	//delete ui;
}

void About::show()
{
	QDialog::show();
}
