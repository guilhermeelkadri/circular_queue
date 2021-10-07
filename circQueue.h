/***************************************************************************************************
* @file circQueue.h
* @brief Fila circular
* @details tab == 2 spaces!
* @author Guilherme Ribeiro
* @date 07/2020
***************************************************************************************************/
#ifndef __CIRCQUEUE__H__
#define __CIRCQUEUE__H__

/***************************************************************************************************
* Includes
***************************************************************************************************/
#include "stdint.h"

/***************************************************************************************************
* Defines
***************************************************************************************************/

/***************************************************************************************************
* Types
***************************************************************************************************/
typedef uint8_t dataType;
typedef uint8_t B;

typedef struct
{
  uint8_t   queueFront;
  uint8_t   queueRear;
  uint8_t   queueSize;
  uint8_t   queueCapacity;
  dataType  *data;
  uint8_t   data_size;
} Queue;

/***************************************************************************************************
* Prototypes
***************************************************************************************************/

Queue    *createQueue      (uint8_t capacity, uint8_t data_size);
B         queueIsFull      (Queue *queue);
B         queueIsEmpty     (Queue *queue);
B         enqueue          (Queue *queue, dataType *message);
B         dequeue          (Queue *queue);
B         queueGetFront    (Queue *queue, dataType *message);
B         queueGetRear     (Queue *queue, dataType *message);


#endif
