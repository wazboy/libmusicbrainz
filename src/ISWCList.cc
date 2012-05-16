/* --------------------------------------------------------------------------

   libmusicbrainz4 - Client library to access MusicBrainz

   Copyright (C) 2012 Andrew Hawkins

   This file is part of libmusicbrainz4.

   This library is free software; you can redistribute it and/or
   modify it under the terms of v2 of the GNU Lesser General Public
   License as published by the Free Software Foundation.

   libmusicbrainz4 is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this library.  If not, see <http://www.gnu.org/licenses/>.

     $Id$

----------------------------------------------------------------------------*/

#include "config.h"
#include "musicbrainz4/defines.h"

#include "musicbrainz4/ISWCList.h"

#include "musicbrainz4/ISWC.h"

class MusicBrainz4::CISWCListPrivate
{
	public:
		CISWCListPrivate()
		{
		}
};

MusicBrainz4::CISWCList::CISWCList(const XMLNode& Node)
:	CListImpl<CISWC>(),
	m_d(new CISWCListPrivate)
{
	if (!Node.isEmpty())
	{
		//std::cout << "ISWCList node: " << std::endl << Node.createXMLString(true) << std::endl;

		Parse(Node);
	}
}

MusicBrainz4::CISWCList::CISWCList(const CISWCList& Other)
:	CListImpl<CISWC>(),
	m_d(new CISWCListPrivate)
{
	*this=Other;
}

MusicBrainz4::CISWCList& MusicBrainz4::CISWCList::operator =(const CISWCList& Other)
{
	if (this!=&Other)
	{
		CListImpl<CISWC>::operator =(Other);
	}

	return *this;
}

MusicBrainz4::CISWCList::~CISWCList()
{
	delete m_d;
}

MusicBrainz4::CISWCList *MusicBrainz4::CISWCList::Clone()
{
	return new CISWCList(*this);
}

void MusicBrainz4::CISWCList::ParseAttribute(const std::string& Name, const std::string& Value)
{
	CListImpl<CISWC>::ParseAttribute(Name,Value);
}

void MusicBrainz4::CISWCList::ParseElement(const XMLNode& Node)
{
	CListImpl<CISWC>::ParseElement(Node);
}

std::string MusicBrainz4::CISWCList::GetElementName()
{
	return "iswc-list";
}

std::ostream& MusicBrainz4::CISWCList::Serialise(std::ostream& os) const
{
	os << "ISWC list:" << std::endl;

	CListImpl<CISWC>::Serialise(os);

	return os;
}