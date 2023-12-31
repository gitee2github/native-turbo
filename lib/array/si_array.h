// Copyright (c) 2023 Huawei Technologies Co.,Ltd. All rights reserved.
//
// native-turbo is licensed under Mulan PSL v2.
// You can use this software according to the terms and conditions of the Mulan
// PSL v2.
// You may obtain a copy of Mulan PSL v2 at:
//         http://license.coscl.org.cn/MulanPSL2
// THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
// KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
// See the Mulan PSL v2 for more details.

#ifndef _SI_ARRAY_H
#define _SI_ARRAY_H

#include <stdbool.h>
#include <stdint.h>

#include "si_common.h"

typedef struct {
	void *data;
	uint32_t len;
} si_array_t;

si_array_t *si_array_new(uint32_t elem_size);
void si_array_free(si_array_t *_arr);

int si_array_append_vals(si_array_t *_arr, void *data, uint32_t elem_size);

static inline int si_array_append(si_array_t *arr, void *data)
{
	return si_array_append_vals(arr, data, 1);
}

void si_array_sort(si_array_t *arr, si_cmp_func cmp_func);

// string array
typedef int (*si_foreach_func)(const void *item, void *pridata);
si_array_t *si_array_new_strings(void);
void si_array_free_strings(si_array_t *_arr);
int si_array_append_strings(si_array_t *_arr, char *item);
bool si_array_in_strings(si_array_t *_arr, char *item);
int si_array_append_strings_uniq(si_array_t *_arr, char *item);
void si_array_foreach_strings(si_array_t *_arr, si_foreach_func foreach_func, void *pridata);

#endif /* _SI_ARRAY_H */
