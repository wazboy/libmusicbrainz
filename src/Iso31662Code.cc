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

#include "musicbrainz5/Iso31662Code.h"


class MusicBrainz5::CIso31662CodePrivate
{
	public:
		std::string m_Iso31662Code;
};

MusicBrainz5::CIso31662Code::CIso31662Code(const XMLNode& Node)
:	CEntity(),
	m_d(new CIso31662CodePrivate)
{
	if (!Node.isEmpty())
	{
		//std::cout << "Iso31662Code node: " << std::endl << Node.createXMLString(true) << std::endl;

		Parse(Node);

		if (Node.getText())
			ProcessItem(Node,m_d->m_Iso31662Code);
	}
}

MusicBrainz5::CIso31662Code::CIso31662Code(const CIso31662Code& Other)
:	CEntity(),
	m_d(new CIso31662CodePrivate)
{
	*this=Other;
}

MusicBrainz5::CIso31662Code& MusicBrainz5::CIso31662Code::operator =(const CIso31662Code& Other)
{
	if (this!=&Other)
	{
		Cleanup();

		CEntity::operator =(Other);

		m_d->m_Iso31662Code=Other.m_d->m_Iso31662Code;
	}

	return *this;
}

MusicBrainz5::CIso31662Code::~CIso31662Code()
{
	Cleanup();

	delete m_d;
}

void MusicBrainz5::CIso31662Code::Cleanup()
{
}

MusicBrainz5::CIso31662Code *MusicBrainz5::CIso31662Code::Clone()
{
	return new CIso31662Code(*this);
}

void MusicBrainz5::CIso31662Code::ParseAttribute(const std::string& Name, const std::string& /*Value*/)
{
	std::cerr << "Unrecognised Iso31662Code attribute: '" << Name << "'" << std::endl;
}

void MusicBrainz5::CIso31662Code::ParseElement(const XMLNode& Node)
{
	std::string NodeName=Node.getName();

	std::cerr << "Unrecognised Iso31662Code element: '" << NodeName << "'" << std::endl;
}

std::string MusicBrainz5::CIso31662Code::GetElementName()
{
	return "iso-3166-2-code";
}

std::string MusicBrainz5::CIso31662Code::Iso31662Code() const
{
	return m_d->m_Iso31662Code;
}

std::ostream& MusicBrainz5::CIso31662Code::Serialise(std::ostream& os) const
{
	os << "Iso31662Code:" << std::endl;

	CEntity::Serialise(os);

	os << "\tIso31662Code: " << Iso31662Code() << std::endl;

	return os;
}
