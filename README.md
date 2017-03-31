# concurrent merge sort on singly-linked list

`mergesort-concurrent` implements merge sort on linked list concurrently.

Tasks give a framework for studying concurrency:

* Restricting number of threads in thread pools.
* Relaxing task boundaries so that overhead associated with task management
  is kept reasonable.

The strategy to implement merge sort concurrently:

* Make recursive calls tasks
* No need to wait for tasks to complete after spawning them
* Tasks that creates sub-tasks can be allowed to terminated

## Build
For input integer 
```bash
make
```

For input word file
```bash
make sort_phonebook
```

## Run
For input integer
```bash
./sort [thread count] [data count]
```
Then input integer data line-by-line
```bash
make check
```
Simple test suite.

For input word file
```bash
./sort_phonebook [thread count] [word file]
```
simple test
```bash
make test_phonebook
```

# Licensing
`mergesort-concurrent` is freely redistributable under the two-clause BSD
License. Use of this source code is governed by a BSD-style license that can
be found in the `LICENSE` file.
