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

#include "config.h"
#include "musicbrainz5/defines.h"

#include "musicbrainz5/Iso31662CodeList.h"

#include "musicbrainz5/Iso31662Code.h"

class MusicBrainz5::CIso31662CodeListPrivate
{
	public:
		CIso31662CodeListPrivate()
		{
		}
};

MusicBrainz5::CIso31662CodeList::CIso31662CodeList(const XMLNode& Node)
:	CListImpl<CIso31662Code>(),
	m_d(new CIso31662CodeListPrivate)
{
	if (!Node.isEmpty())
	{
		//std::cout << "Iso31662CodeList node: " << std::endl << Node.createXMLString(true) << std::endl;

		Parse(Node);
	}
}

MusicBrainz5::CIso31662CodeList::CIso31662CodeList(const CIso31662CodeList& Other)
:	CListImpl<CIso31662Code>(),
	m_d(new CIso31662CodeListPrivate)
{
	*this=Other;
}

MusicBrainz5::CIso31662CodeList& MusicBrainz5::CIso31662CodeList::operator =(const CIso31662CodeList& Other)
{
	if (this!=&Other)
	{
		CListImpl<CIso31662Code>::operator =(Other);
	}

	return *this;
}

MusicBrainz5::CIso31662CodeList::~CIso31662CodeList()
{
	delete m_d;
}

MusicBrainz5::CIso31662CodeList *MusicBrainz5::CIso31662CodeList::Clone()
{
	return new CIso31662CodeList(*this);
}

void MusicBrainz5::CIso31662CodeList::ParseAttribute(const std::string& Name, const std::string& Value)
{
	CListImpl<CIso31662Code>::ParseAttribute(Name,Value);
}

void MusicBrainz5::CIso31662CodeList::ParseElement(const XMLNode& Node)
{
	CListImpl<CIso31662Code>::ParseElement(Node);
}

std::string MusicBrainz5::CIso31662CodeList::GetElementName()
{
	return "iso-3661-2-code-list";
}

std::ostream& MusicBrainz5::CIso31662CodeList::Serialise(std::ostream& os) const
{
	os << "Iso31662Code list:" << std::endl;

	CListImpl<CIso31662Code>::Serialise(os);

	return os;
}
