/* --------------------------------------------------------------------------

   libmusicbrainz5 - Client library to access MusicBrainz

   Copyright (C) 2011 Andrew Hawkins

   This file is part of libmusicbrainz5.

   This library is free software; you can redistribute it and/or
   modify it under the terms of v2 of the GNU Lesser General Public
   License as published by the Free Software Foundation.

   libmusicbrainz5 is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this library.  If not, see <http://www.gnu.org/licenses/>.

     $Id$

----------------------------------------------------------------------------*/

#ifndef _MUSICBRAINZ5_RELEASE_GROUP_H
#define _MUSICBRAINZ5_RELEASE_GROUP_H

#include <string>
#include <iostream>

#include "musicbrainz5/Entity.h"
#include "musicbrainz5/ReleaseList.h"
#include "musicbrainz5/RelationList.h"
#include "musicbrainz5/TagList.h"
#include "musicbrainz5/UserTagList.h"
#include "musicbrainz5/SecondaryTypeList.h"

#include "musicbrainz5/xmlParser.h"

namespace MusicBrainz5
{
	class CReleaseGroupPrivate;

	class CArtistCredit;
	class CRating;
	class CUserRating;
	class CSecondaryType;

	class CReleaseGroup: public CEntity
	{
	public:
		CReleaseGroup(const XMLNode& Node=XMLNode::emptyNode());
		CReleaseGroup(const CReleaseGroup& Other);
		CReleaseGroup& operator =(const CReleaseGroup& Other);
		virtual ~CReleaseGroup();

		virtual CReleaseGroup *Clone();

		std::string ID() const;

		/**
		 * @deprecated Returns the type for this release group
		 *
		 * Returns the type for this release group.
		 *
		 * <b>This method is deprecated, please use MusicBrainz5::CReleaseGroup::PrimaryType
		 * and MusicBrainz5::CReleaseGroup::SecondaryTypeList</b>
		 *
		 * @return The type for this release group
		 */

		LIBMB5_DEPRECATED(MusicBrainz5::CReleaseGroup::PrimaryType) std::string Type() const;
		std::string PrimaryType() const;
		std::string Title() const;
		std::string Disambiguation() const;
		std::string FirstReleaseDate() const;
		CArtistCredit *ArtistCredit() const;
		CReleaseList *ReleaseList() const;

		/**
		 * @deprecated Returns the <b>last</b> relation list for this release group
		 *
		 * Returns the <b>last</b> relation list for this release group. To return all
		 * relation lists, see MusicBrainz5::CReleaseGroup::RelationListList
		 *
		 * <b>This method is deprecated, please use MusicBrainz5::CReleaseGroup::RelationListList</b>
		 *
		 * @return The <b>last</b> relation list for this release group
		 */

		LIBMB5_DEPRECATED(MusicBrainz5::CReleaseGroup::RelationListList) CRelationList *RelationList() const;
		CRelationListList *RelationListList() const;
		CTagList *TagList() const;
		CUserTagList *UserTagList() const;
		CRating *Rating() const;
		CUserRating *UserRating() const;
		CSecondaryTypeList *SecondaryTypeList() const;

		virtual std::ostream& Serialise(std::ostream& os) const;
		static std::string GetElementName();

	protected:
		virtual bool ParseAttribute(const std::string& Name, const std::string& Value);
		virtual bool ParseElement(const XMLNode& Node);

	private:
		void Cleanup();

		CReleaseGroupPrivate * const m_d;
	};
}

#endif