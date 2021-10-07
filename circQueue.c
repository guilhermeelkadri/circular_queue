/***************************************************************************************************
* @file circQueue.h
* @brief Fila circular
* @details tab == 2 spaces!
* @author Guilherme Ribeiro
* @date 07/2020
***************************************************************************************************/
/***************************************************************************************************
* Includes
***************************************************************************************************/
#include "circqueue.h"
#include "stdlib.h"
#include "string.h"

/***************************************************************************************************
* Externals
***************************************************************************************************/

/***************************************************************************************************
* Vars
***************************************************************************************************/

/***************************************************************************************************
* @brief Cria determinada fila com tamanho e capacidade definido. 
***************************************************************************************************/
Queue *createQueue(uint8_t capacity, uint8_t data_size)
{
  Queue *queue = (Queue*)SRAM_Malloc(sizeof(Queue));

  queue->queueCapacity = capacity;
  queue->queueFront    = 0;
  queue->queueSize     = 0;
  queue->queueRear     = capacity - 1;

  queue->data       = (dataType*)SRAM_Malloc(capacity * data_size);
  queue->data_size  = data_size;

  if(queue == NULL || queue->data == NULL)
    return NULL;

  return queue;
}

/***************************************************************************************************
* @brief Verifica se a fila esta cheia 
***************************************************************************************************/
B queueIsFull(Queue *queue)
{
  return (queue->queueSize == queue->queueCapacity);
}

/***************************************************************************************************
* @brief Verifica se a fila esta vazia
***************************************************************************************************/
B queueIsEmpty(Queue *queue)
{
  return (queue->queueSize == 0);
}

/***************************************************************************************************
* @brief Desinfilera primeiro evento da fila.
***************************************************************************************************/
B enqueue(Queue *queue, dataType *data)
{
  if(queueIsFull(queue))
    return false;

  queue->queueRear = (queue->queueRear+1)%queue->queueCapacity;
  memcpy(&queue->data[queue->queueRear], data, queue->data_size); 
  queue->queueSize++;
  return true;
}

/***************************************************************************************************
* @brief Desinfilera primeiro evento da fila.
***************************************************************************************************/
B dequeue(Queue *queue)
{
  if(queueIsEmpty(queue))
    return false;

  queue->queueFront = (queue->queueFront+1)%queue->queueCapacity; 
  queue->queueSize--; 
  return true;
}

/***************************************************************************************************
* @brief Getter do cabeça da fila. Retorna NULL caso contrário.
***************************************************************************************************/
B queueGetFront(Queue *queue, dataType *message)
{
  *message = queue->data[queue->queueFront];

  if(queueIsEmpty(queue) || message == NULL)
    return false;

  return true;
}

/***************************************************************************************************
* @brief Getter do rabo da fila. Retorna NULL caso contrário.
***************************************************************************************************/
B queueGetRear(Queue *queue, dataType *message)
{
  *message = queue->data[queue->queueFront];

  if(queueIsEmpty(queue) || message == NULL)
    return false;

  return true;
}
