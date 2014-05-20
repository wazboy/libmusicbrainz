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

#include "musicbrainz5/BeginArea.h"
#include "musicbrainz5/Iso31662CodeList.h"

class MusicBrainz5::CBeginAreaPrivate
{
public:
		CBeginAreaPrivate()
		:	m_Iso31662CodeList(0)
		{
		}

		std::string m_ID;
		std::string m_Name;
		std::string m_SortName;
		CIso31662CodeList *m_Iso31662CodeList;
};

MusicBrainz5::CBeginArea::CBeginArea(const XMLNode& Node)
:	CEntity(),
	m_d(new CBeginAreaPrivate)
{
	if (!Node.isEmpty())
	{
		//std::cout << "BeginArea node: " << std::endl << Node.createXMLString(true) << std::endl;

		Parse(Node);
	}
}

MusicBrainz5::CBeginArea::CBeginArea(const CBeginArea& Other)
:	CEntity(),
	m_d(new CBeginAreaPrivate)
{
	*this=Other;
}

MusicBrainz5::CBeginArea& MusicBrainz5::CBeginArea::operator =(const CBeginArea& Other)
{
	if (this!=&Other)
	{
		Cleanup();

		CEntity::operator =(Other);

		m_d->m_ID=Other.m_d->m_ID;
		m_d->m_Name=Other.m_d->m_Name;
		m_d->m_SortName=Other.m_d->m_SortName;

		if (Other.m_d->m_Iso31662CodeList)
			m_d->m_Iso31662CodeList=new CIso31662CodeList(*Other.m_d->m_Iso31662CodeList);
	}

	return *this;
}

MusicBrainz5::CBeginArea::~CBeginArea()
{
	Cleanup();

	delete m_d;
}

void MusicBrainz5::CBeginArea::Cleanup()
{
	delete m_d->m_Iso31662CodeList;
	m_d->m_Iso31662CodeList=0;
}

MusicBrainz5::CBeginArea *MusicBrainz5::CBeginArea::Clone()
{
	return new CBeginArea(*this);
}

void MusicBrainz5::CBeginArea::ParseAttribute(const std::string& Name, const std::string& Value)
{
	if ("id"==Name)
		m_d->m_ID=Value;
	else
	{
		std::cerr << "Unrecognised area attribute: '" << Name << "'" << std::endl;
	}
}

void MusicBrainz5::CBeginArea::ParseElement(const XMLNode& Node)
{
	std::string NodeName=Node.getName();

	if ("name"==NodeName)
	{
		ProcessItem(Node,m_d->m_Name);
	}
	else if ("sort-name"==NodeName)
	{
		ProcessItem(Node,m_d->m_SortName);
	}
	else if ("iso-3166-2-code-list"==NodeName)
	{
		ProcessItem(Node,m_d->m_Iso31662CodeList);
	}
	else {
		std::cerr << "Unrecognised area element: '" << NodeName << std::endl;
	}
}

std::string MusicBrainz5::CBeginArea::GetElementName()
{
	return "begin-area";
}

std::string MusicBrainz5::CBeginArea::ID() const
{
	return m_d->m_ID;
}

std::string MusicBrainz5::CBeginArea::Name() const
{
	return m_d->m_Name;
}

std::string MusicBrainz5::CBeginArea::SortName() const
{
	return m_d->m_SortName;
}

MusicBrainz5::CIso31662CodeList * MusicBrainz5::CBeginArea::Iso31662CodeList() const
{
	return m_d->m_Iso31662CodeList;
}

std::ostream& MusicBrainz5::CBeginArea::Serialise(std::ostream& os) const
{
	os << "BeginArea:" << std::endl;

	CEntity::Serialise(os);

	os << "\tID:        " << ID() << std::endl;
	os << "\tName:      " << Name() << std::endl;
	os << "\tSort Name: " << SortName() << std::endl;

    if(Iso31662CodeList())
        os << *Iso31662CodeList() << std::endl;

	return os;
}
