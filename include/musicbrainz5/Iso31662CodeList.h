/* --------------------------------------------------------------------------

   libmusicbrainz5 - Client library to access MusicBrainz

   Copyright (C) 2014 Galen Sampson

   This file is part of libmusicbrainz5.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   libmusicbrainz5 is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this library.  If not, see <http://www.gnu.org/licenses/>.

     $Id$

----------------------------------------------------------------------------*/

#ifndef _MUSICBRAINZ5_ISO31662CODELIST_LIST_H
#define _MUSICBRAINZ5_ISO31662CODELIST_LIST_H

#include <string>
#include <iostream>

#include "musicbrainz5/ListImpl.h"

#include "musicbrainz5/xmlParser.h"

namespace MusicBrainz5
{
	class CIso31662Code;
	class CIso31662CodeListPrivate;

	class CIso31662CodeList: public CListImpl<CIso31662Code>
	{
	public:
		CIso31662CodeList(const XMLNode& Node=XMLNode::emptyNode());
		CIso31662CodeList(const CIso31662CodeList& Other);
		CIso31662CodeList& operator =(const CIso31662CodeList& Other);
		virtual ~CIso31662CodeList();

		virtual CIso31662CodeList *Clone();

		virtual std::ostream& Serialise(std::ostream& os) const;
		static std::string GetElementName();

	protected:
		virtual void ParseAttribute(const std::string& Name, const std::string& Value);
		virtual void ParseElement(const XMLNode& Node);

	private:
		CIso31662CodeListPrivate * const m_d;
	};
}

#endif
