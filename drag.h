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
 *  the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 *  Boston, MA 02111-1307, USA.
 **/
#ifndef drag_h
#define drag_h

#include <q3dragobject.h>
//Added by qt3to4:
#include <QDragMoveEvent>
#include <QDropEvent>

class RegExp;
class RegExpWidget;
class RegExpEditorWindow;

/**
   Class used for drag and drop in the RegExp widget.
   @internal
*/
class RegExpWidgetDrag :public Q3DragObject
{
public:
  RegExpWidgetDrag( RegExp* regexp , QWidget* dragSource);
  ~RegExpWidgetDrag();
  virtual const char * format ( int i = 0 ) const;
  virtual QByteArray encodedData ( const char * ) const;
  static bool canDecode(QDragMoveEvent* event);
  static RegExpWidget* decode(QDropEvent* event, RegExpEditorWindow* window,
                              QWidget* parent);
private:
  RegExp* _regexp;
};

#endif // drag_h