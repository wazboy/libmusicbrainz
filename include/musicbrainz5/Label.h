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

#ifndef _MUSICBRAINZ5_LABEL_H
#define _MUSICBRAINZ5_LABEL_H

#include <string>
#include <iostream>

#include "musicbrainz5/Entity.h"
#include "musicbrainz5/IPIList.h"
#include "musicbrainz5/ReleaseList.h"
#include "musicbrainz5/AliasList.h"
#include "musicbrainz5/RelationList.h"
#include "musicbrainz5/TagList.h"
#include "musicbrainz5/UserTagList.h"

#include "musicbrainz5/xmlParser.h"

namespace MusicBrainz5
{
	class CLabelPrivate;

	class CLifespan;
	class CRating;
	class CUserRating;

	class CLabel: public CEntity
	{
	public:
		CLabel(const XMLNode& Node=XMLNode::emptyNode());
		CLabel(const CLabel& Other);
		CLabel& operator =(const CLabel& Other);
		virtual ~CLabel();

		virtual CLabel *Clone();

		std::string ID() const;
		std::string Type() const;
		std::string Name() const;
		std::string SortName() const;
		int LabelCode() const;

		/**
		 * @deprecated Returns one of the IPIs for this label
		 *
		 * Returns one of the IPIs for this label. To return all
		 * IPIs, see MusicBrainz5::CLabel::IPIList
		 *
		 * <b>This method is deprecated, please use MusicBrainz5::CLabel::IPIList</b>
		 *
		 * @return One of the IPIs for this label
		 */

		LIBMB5_DEPRECATED(MusicBrainz5::CLabel::IPIList) std::string IPI() const;
		CIPIList *IPIList() const;
		std::string Disambiguation() const;
		std::string Country() const;
		CLifespan *Lifespan() const;
		CAliasList *AliasList() const;
		CReleaseList *ReleaseList() const;

		/**
		 * @deprecated Returns the <b>last</b> relation list for this label
		 *
		 * Returns the <b>last</b> relation list for this label. To return all
		 * relation lists, see MusicBrainz5::CLabel::RelationListList
		 *
		 * <b>This method is deprecated, please use MusicBrainz5::CLabel::RelationListList</b>
		 *
		 * @return The <b>last</b> relation list for this label
		 */

		LIBMB5_DEPRECATED(MusicBrainz5::CLabel::RelationListList) CRelationList *RelationList() const;
		CRelationListList *RelationListList() const;
		CTagList *TagList() const;
		CUserTagList *UserTagList() const;
		CRating *Rating() const;
		CUserRating *UserRating() const;

		virtual std::ostream& Serialise(std::ostream& os) const;
		static std::string GetElementName();

	protected:
		virtual bool ParseAttribute(const std::string& Name, const std::string& Value);
		virtual bool ParseElement(const XMLNode& Node);

	private:
		void Cleanup();

		CLabelPrivate * const m_d;
	};
}

#endif