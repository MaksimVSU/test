#include "list.h"
#include"rez.h"
#include <stdio.h>
#include <stdlib.h>
List_IN *to_head_in(List_IN *current, List_IN *head)
{
    current=head;
    return current;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ ПЕРЕХОДА В НАЧАЛО СПИСКА(out)///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
List_OUT *to_head_out(List_OUT *current_out, List_OUT *head_out)
{
    current_out=head_out;
    return current_out;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ ПЕРЕХОДА НА СЛЕД ЭЛЕМЕНТ////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
List_IN *next_el_in(List_IN *current)
{
    List_IN *next_el = current->next;
    return next_el;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ ПЕРЕХОДА НА СЛЕД ЭЛЕМЕНТ(OUT)///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
List_OUT *next_el_out(List_OUT *current)
{
    List_OUT *next_el = current->next_out;
    return next_el;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ УДАЛЕНЯИ ЭЛЕМЕНТА///////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
List_IN *del_in(List_IN *current)
{
    List_IN *del=current;
    current=next_el_in(current);
    free(del);
    return current;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ УДАЛЕНЯИ ЭЛЕМЕНТА(OUT)//////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
List_OUT *del_out(List_OUT *current)
{
    List_OUT *del=current;
    current=current->next_out;
    free(del);
    return current;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ ДЛЯ ДОБАВЛЕНИЯ ЧИСЛА////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float *addperemenai(FILE *input, int size)
{
    float *peremenai;
    peremenai=malloc(size*sizeof(float));
    for(int i=0;i<size;i++)
    {
        fscanf(input,"%f",&peremenai[i]);
    }
    return peremenai;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ ДЛЯ ДОБАВЛЕНИЯ ЭЛЕМЕНТА ВВОДА///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void add_el_in(List_IN *current, FILE *input)
{
    List_IN *tmp=malloc(1*sizeof(List_IN));
    fscanf(input,"%i %c",&tmp->size,&tmp->deistvie);
    if (tmp->deistvie!='!')
    {
        tmp->peremenai_1=addperemenai(input,tmp->size);
        tmp->peremenai_2=addperemenai(input,tmp->size);
    }
    else if(tmp->deistvie=='!')
    {
        tmp->peremenai_1=addperemenai(input,tmp->size);
        tmp->peremenai_2=NULL;
    }
    tmp->next=NULL;
    current->next=tmp;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ ДЛЯ ДОБАВЛЕНИЯ ЭЛЕМЕНТА ВЫВОДА//////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void add_el_out(List_OUT *current_OUT, List_IN *current)
{
    List_OUT *tmp_res=malloc(1*sizeof(List_OUT));
    if (current->size!=1)
    {
        tmp_res->rez=vector(current->deistvie,current->size,current->peremenai_1,current->peremenai_2);
    }
    else
    {
        tmp_res->rez=num(current->deistvie,current->peremenai_1,current->peremenai_2);
    }
    tmp_res->next_out=NULL;
    current_OUT->next_out=tmp_res;
}
