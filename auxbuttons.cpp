/*
 *  Copyright (c) 2002-2003 Jesper K. Pedersen <blackie@kde.org>
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License version 2 as published by the Free Software Foundation.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public License
 *  along with this library; see the file COPYING.LIB.  If not, write to
 *  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *  Boston, MA 02110-1301, USA.
 **/
#include "auxbuttons.h"

#ifdef QT_ONLY
  #include "compat.h"
  #include "images.h"
#else
  #include "auxbuttons.moc"
  #include <kiconloader.h>
  #include <klocale.h>
#endif



#include <qtoolbutton.h>
//Added by qt3to4:
#include <QBoxLayout>
#include <Q3WhatsThis>
#include "util.h"

AuxButtons::AuxButtons( QWidget* parent, const char* name = 0)
  :Q3DockWindow( Q3DockWindow::InDock, parent, name)
{
  QBoxLayout* layout = boxLayout();

  _undo = new QToolButton( this );
  _undo->setIcon(  Util::getSystemIconSet(QString::fromLatin1("edit-undo") ) );
  layout->addWidget( _undo );
  connect( _undo, SIGNAL(clicked()), this, SIGNAL(undo()) );
  _undo->setToolTip( i18n( "Undo" ) );

  _redo = new QToolButton( this );
  _redo->setIcon(  Util::getSystemIconSet(QString::fromLatin1("edit-redo") ) );
  layout->addWidget( _redo );
  connect( _redo, SIGNAL(clicked()), this, SIGNAL(redo()) );
  _redo->setToolTip( i18n( "Redo" ) );

  _cut = new QToolButton( this );
  _cut->setIcon(  Util::getSystemIconSet(QString::fromLatin1("edit-cut") ) );
  layout->addWidget( _cut );
  connect( _cut, SIGNAL(clicked()), this, SIGNAL(cut()) );
  _cut->setToolTip( i18n( "Cut" ) );

  _copy = new QToolButton( this );
  _copy->setIcon(  Util::getSystemIconSet(QString::fromLatin1("edit-copy") ) );
  layout->addWidget( _copy );
  connect( _copy, SIGNAL(clicked()), this, SIGNAL(copy()) );
  _copy->setToolTip( i18n( "Copy" ) );

  _paste = new QToolButton( this );
  _paste->setIcon( Util::getSystemIconSet(QString::fromLatin1("edit-paste")) );
  layout->addWidget( _paste );
  connect( _paste, SIGNAL(clicked()), this, SIGNAL(paste()) );
  _paste->setToolTip( i18n( "Paste" ) );

  _save = new QToolButton( this );
  _save->setIcon( Util::getSystemIconSet(QString::fromLatin1("document-save")) );
  layout->addWidget( _save );
  connect( _save, SIGNAL(clicked()), this, SIGNAL(save()) );
  _save->setToolTip( i18n( "Save" ) );


  QToolButton* button = new QToolButton(this);
  button->setIcon(static_cast<QIcon> (Util::getSystemIcon( QString::fromLatin1("help-whatsthis") ) ));
  layout->addWidget( button );
  connect(button, SIGNAL(clicked()), this, SLOT(slotEnterWhatsThis()));

  _undo->setEnabled( false );
  _redo->setEnabled( false );

}

void AuxButtons::slotEnterWhatsThis()
{
  Q3WhatsThis::enterWhatsThisMode ();
}

void AuxButtons::slotCanUndo( bool b )
{
  _undo->setEnabled( b );
}

void AuxButtons::slotCanRedo( bool b )
{
  _redo->setEnabled( b );
}

void AuxButtons::slotCanCut( bool b )
{
  _cut->setEnabled( b );
}

void AuxButtons::slotCanCopy( bool b )
{
  _copy->setEnabled( b );
}

void AuxButtons::slotCanPaste( bool b )
{
  _paste->setEnabled( b );
}

void AuxButtons::slotCanSave( bool b )
{
  _save->setEnabled( b );
}

