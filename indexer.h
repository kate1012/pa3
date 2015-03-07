#ifndef _INDEXER_H_
#define _INDEXER_H_

#include "sorted_list.h"

typedef struct indexer {
    list_t *entries;
} indexer_t;

/*
 * Creates an indexer. The caller is responsible for freeing the
 * allocated memory.
 */
indexer_t *create_indexer();

/*
 * Destroys an indexer.
 */
void destroy_indexer(indexer_t *);

/*
 * Runs the indexer, given the path to the directory to recursively
 * traverse through.
 */
bool run_indexer(indexer_t *, char *);

typedef struct indexer_entry {
    char *token;
    list_t *records;
} indexer_entry_t;

/*
 * Creates an indexer entry. The caller is responsible for freeing
 * the allocated memory.
 */
indexer_entry_t *create_indexer_entry(char *);

/*
 * Destroys an indexer entry.
 */
void destroy_indexer_entry(indexer_entry_t *);

typedef struct indexer_entry_record {
    char *file_path;
    int count;
} indexer_entry_record_t;

/*
 * Creates an indexer entry record, given the file path. The caller is
 * responsible for freeing the allocated memory.
 */
indexer_entry_record_t *create_indexer_entry_record(char *);

/*
 * Destroys an indexer entry record.
 */
void destroy_indexer_entry_record(indexer_entry_record_t *);

#endif