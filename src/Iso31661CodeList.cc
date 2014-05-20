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

#include "musicbrainz5/Iso31661CodeList.h"

#include "musicbrainz5/Iso31661Code.h"

class MusicBrainz5::CIso31661CodeListPrivate
{
	public:
		CIso31661CodeListPrivate()
		{
		}
};

MusicBrainz5::CIso31661CodeList::CIso31661CodeList(const XMLNode& Node)
:	CListImpl<CIso31661Code>(),
	m_d(new CIso31661CodeListPrivate)
{
	if (!Node.isEmpty())
	{
		//std::cout << "Iso31661CodeList node: " << std::endl << Node.createXMLString(true) << std::endl;

		Parse(Node);
	}
}

MusicBrainz5::CIso31661CodeList::CIso31661CodeList(const CIso31661CodeList& Other)
:	CListImpl<CIso31661Code>(),
	m_d(new CIso31661CodeListPrivate)
{
	*this=Other;
}

MusicBrainz5::CIso31661CodeList& MusicBrainz5::CIso31661CodeList::operator =(const CIso31661CodeList& Other)
{
	if (this!=&Other)
	{
		CListImpl<CIso31661Code>::operator =(Other);
	}

	return *this;
}

MusicBrainz5::CIso31661CodeList::~CIso31661CodeList()
{
	delete m_d;
}

MusicBrainz5::CIso31661CodeList *MusicBrainz5::CIso31661CodeList::Clone()
{
	return new CIso31661CodeList(*this);
}

void MusicBrainz5::CIso31661CodeList::ParseAttribute(const std::string& Name, const std::string& Value)
{
	CListImpl<CIso31661Code>::ParseAttribute(Name,Value);
}

void MusicBrainz5::CIso31661CodeList::ParseElement(const XMLNode& Node)
{
	CListImpl<CIso31661Code>::ParseElement(Node);
}

std::string MusicBrainz5::CIso31661CodeList::GetElementName()
{
	return "iso-3661-1-code-list";
}

std::ostream& MusicBrainz5::CIso31661CodeList::Serialise(std::ostream& os) const
{
	os << "Iso31661Code list:" << std::endl;

	CListImpl<CIso31661Code>::Serialise(os);

	return os;
}
