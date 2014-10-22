// http://stackoverflow.com/questions/3732856/arraylist-in-c
#ifndef _ARRAYLIST_H
#define _ARRAYLIST_H

#include <stdio.h>

typedef void *value_type;

typedef struct arraylist arraylist; 
struct arraylist {
  int size;
  value_type* data;
};

void arraylist_initial(struct arraylist *list) {
  list->size = 0;
  list->data = NULL;
}

int arraylist_get_size(const struct arraylist list) {
  return list.size;
}

value_type* arraylist_get_data_collection(const struct arraylist list) {
  return list.data;
}

void arraylist_set_data_collection(struct arraylist *list, value_type* data) {
  list->data = data;
}

value_type arraylist_get(const struct arraylist list, int index) {
  if(index < arraylist_get_size(list)) {
    return list.data[index];
  }
  else {
    return NULL;
  }
}

void arraylist_add(struct arraylist *list, value_type value) {
  int size = arraylist_get_size(*list);
  value_type new_data[size + 1];

  int index = 0;
  for(; index != size; ++index) {
    new_data[index] = arraylist_get(*list, index);
  }
  new_data[index] = value;

  arraylist_set_data_collection(list, new_data);

  ++list->size;
}

int arraylist_indexof(const struct arraylist list, value_type value) {
  int index = 0;
  for(; index != arraylist_get_size(list); ++index) {
    if(strcmp(list.data[index], value) == 0) {
      return index;
    }
  }

  return -1;
}

// int main(void){
//   struct arraylist list;

//   arraylist_initial(&list);

//   arraylist_add(&list, "1");
//   arraylist_add(&list, "2");
//   arraylist_add(&list, "3");
//   arraylist_add(&list, "4");
//   arraylist_add(&list, "5");
//   arraylist_add(&list, "6");

//   int index = 0;
//   for(; index != 6; ++index) {
//     printf("CHECK: %s\n", arraylist_get(list, index));
//   }

//   return 0;
// }

#endif