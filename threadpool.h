#ifndef THREAD_H_
#define THREAD_H_

#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>

/*========== Task ==========*/

/**
 * @struct _task threadpool.h "threadpool.h"
 * @brief The data structure for a task which will be put in a task queue
 */
typedef struct _task {
    void (*func)(void *);   ///< Pointer to task function
    void *arg;              ///< Pointer to the arguments passed to _func_
    struct _task *next;     ///< Pointer to the next task
    struct _task *last;     ///< Pointer to the previous task
} task_t;

int task_free(task_t *the_task);

/*========== Task queue ==========*/

/**
 * @struct _tqueue_t threadpool.h "threadpool.h"
 * @brief The data structure for a task queue of _task\_t_
 */
typedef struct _tqueue_t {
    task_t *head;           ///< Pointer to the fist _task\_t_ in queue
    task_t *tail;           ///< Pointer to the last _task\_t_ in queue
    pthread_mutex_t mutex;  ///< The mutex lock of this queue
    pthread_cond_t cond;    ///< The conitional variable of this queue
    uint32_t size;          ///< The size of the queue
} tqueue_t;

int tqueue_init(tqueue_t *the_queue);
task_t *tqueue_pop(tqueue_t *the_queue);
uint32_t tqueue_size(tqueue_t *the_queue);
int tqueue_push(tqueue_t *the_queue, task_t *task);
int tqueue_free(tqueue_t *the_queue);

/*========== Thread pool ==========*/

/**
 * @struct _tpool_t threadpool.h "threadpool.h"
 * @brief The data structure for managing thread pool
 */
typedef struct _tpool_t {
    pthread_t *threads; ///< Pointer to the array of threads
    uint32_t count;     ///< Number of working threads
    tqueue_t *queue;    ///< Pointer to the task queue
} tpool_t;

int tpool_init(tpool_t *the_pool, uint32_t count, void *(*func)(void *));
int tpool_free(tpool_t *the_pool);

#endif
