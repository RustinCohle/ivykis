/*
 * ivykis, an event handling library
 * Copyright (C) 2012 Lennert Buytenhek
 * Dedicated to Marija Kulikova.
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License version
 * 2.1 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License version 2.1 for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License version 2.1 along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef __IV_RCU_H
#define __IV_RCU_H

#include <iv_list.h>

#ifdef __cplusplus
extern "C" {
#endif

struct iv_rcu_head {
	void		*cookie;
	void		(*handler)(void *);

	struct iv_list_head	list;
};

void iv_rcu_read_lock(void);
void iv_rcu_read_unlock(void);
void iv_rcu_call(struct iv_rcu_head *);
void iv_rcu_synchronize(void);

#ifdef __cplusplus
}
#endif


#endif
