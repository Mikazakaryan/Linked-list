#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct linked_list
{
  int value;
  struct linked_list *next;
} linked_list_t;

struct linked_list *head = NULL;
struct linked_list *current = NULL;


struct linked_list* add_to_list(int value, bool add_to_end) {
  if(NULL == head) {
    linked_list_t *list = malloc(sizeof(linked_list_t));
    if(NULL == list) {
      return NULL;
    }
    list->value = value;
    list->next = NULL;
    head = current = list;
    return list;
  }
  linked_list_t *list = malloc(sizeof(linked_list_t));
  if(NULL == list) {
    return NULL;
  }
  list->value = value;
  list->next = NULL;
  if(add_to_end) {
    current->next = list;
    current = list;
  }
  else {
    list->next = head;
    head = list;
  }
  return list;
}

void print_list(void) {
  linked_list_t *list = head;
  while(list != NULL) {
    printf("%d \n",list->value);
    list = list->next;
  }
  printf("\n");
}

int main(void)
{
  linked_list_t *list = NULL;
  for(int i = 5; i<10; i++){
    add_to_list(i,true);
  }
  print_list();
  for(int i = 4; i>0; i--){
    add_to_list(i,false);
  }
  print_list();
  for(int i = 10; i<16; i++){
    add_to_list(i,true);
  }
  print_list();
  return 0;
}
