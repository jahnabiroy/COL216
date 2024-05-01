# BEST CACHE PERFORMANCE PARAMETERS

## Cache Simulator was run on the following combination of parameters.

1. Write-Allocate, Write-Back, LRU
2. Write-Allocate, Write-Back, FIFO
3. Write-No-Allocate, Write-Back, LRU
4. Write-No-Allocate, Write-Back, FIFO
5. Write-Allocate, Write-Through, LRU
6. Write-Allocate, Write-Through, FIFO
7. Write-No-Allocate, Write-Through, LRU
8. Write-No-Allocate, Write-Through, FIFO

With regards to permutations and combinations, all possible combinations of parameters were thus chosen for testing.

## Test Results

Testing was primarily done for the following test case -

`./cacheSim 256 4 16 <writeMissPolicy> <writeHitPolicy> <replacementPolicy> < gcc.trace`

For interpreting the combination results, with constant cache size of 16,384 bytes, we use hit rates and miss penalties.

`Hit Rate = Total Hits/ Total Operations`
`Miss Penalty = Total Cycles/ Total Misses (unit : cycles)`

1.  #### write-allocate write-back lru

    `Output :`

    Total Loads : 318197

    Total Stores : 197486

    Load Hits : 314465

    Load Misses : 3732

    Store Hits : 188177

    Store Misses : 9309

    Total Cycles : 9506483

    #### Hit Rate = 0.9747

    #### Miss Penalty = 728.97

2.  #### write-allocate write-back fifo

    `Output :`

    Total Loads : 318197

    Total Stores : 197486

    Load Hits : 298863

    Load Misses : 19334

    Store Hits : 185202

    Store Misses : 12284

    Total Cycles : 20307683

    #### Hit Rate = 0.9387

    #### Miss Penalty = 642.28

3.  #### write-no-allocate write-back lru

    `Output :`

    Total Loads : 318197

    Total Stores : 197486

    Load Hits : 311401

    Load Misses : 6796

    Store Hits : 165875

    Store Misses : 587

    Total Cycles : 17197672

    #### Hit Rate = 0.9255

    #### Miss Penalty = 2329.36

4.  #### write-no-allocate write-back fifo

    `Output :`

    Total Loads : 318197

    Total Stores : 197486

    Load Hits : 296282

    Load Misses : 21915

    Store Hits : 159079

    Store Misses : 188

    Total Cycles : 28134876

    #### Hit Rate = 0.883

    #### Miss Penalty = 1272.89

5.  #### write-allocate write-through lru

    `Output :`

    Total Loads : 318197

    Total Stores : 197486

    Load Hits : 314465

    Load Misses : 3732

    Store Hits : 188177

    Store Misses : 9309

    Total Cycles : 84726483

    #### Hit Rate = 0.9747

    #### Miss Penalty = 6496.931

6.  #### write-allocate write-through fifo

    `Output :`

    Total Loads : 318197

    Total Stores : 197486

    Load Hits : 298863

    Load Misses : 19334

    Store Hits : 185202

    Store Misses : 12284

    Total Cycles : 92157283

    #### Hit Rate = 0.9386

    #### Miss Penalty = 2914.709

7.  ###### write-no-allocate write-through lru

    `Output :`

    Total Loads : 318197

    Total Stores : 197486

    Load Hits : 311401

    Load Misses : 6796

    Store Hits : 165875

    Store Misses : 587

    Total Cycles : 82196872

    #### Hit Rate = 0.9255

    #### Miss Penalty = 11,133.262

8.  ###### write-no-allocate write-through fifo

    `Output :`

    Total Loads : 318197

    Total Stores : 197486

    Load Hits : 296282

    Load Misses : 21915

    Store Hits : 159079

    Store Misses : 188

    Total Cycles : 88237676

    #### Hit Rate = 0.883

    #### Miss Penalty = 297.627

## Conclusion of the test results :

As per the results, write-allocate combined with write-back and LRU replacement policy, seems to perform the best since this combination exploits spatial locality (with allocating entire block from memory into cache on miss), and temporal locality (with least recently used replacement policy to deallocate indices which have not accessed very recently). Also the write-back combination reduces the overall cycles due to the delayed memory access. Hit Rate is the Highest for this strategy and the miss penalty is not very significantly large. The last case of `write-no-allocate write-through fifo` is also a good performing case in terms of miss penalty and hit rate. But due to write-through policy along with write-no-allocate, the number of cycles is much much higher; thus rendering it to not be a very good choice for the case.

Thus, as per theory and tested results, the best performing cache combination is `write-allocate write-back LRU`.

A check was also done to consider the variable parameter of cache size. We consider the case of `256 1 16` and `1 256 4` for the `write-allocate write-back lru strategy`.

### For `256 1 16 write-allocate write-back lru` case :

    Total Loads : 318197

    Total Stores : 197486

    Load Hits : 298863

    Load Misses : 19334

    Store Hits : 185202

    Store Misses : 12284

    Total Cycles : 20307683

    `Hit Rate = 0.9387`

    `Miss Penalty = 642.28`

### For `1 256 4 write-allocate write-back lru` case :

    Total Loads : 318197

    Total Stores : 197486

    Load Hits : 304553

    Load Misses : 13644

    Store Hits : 166764

    Store Misses : 30722

    Total Cycles : 8200083

    `Hit Rate = 0.914`

    `Miss Penalty = 184.82`

According to the above data, fully associative cache with lesser cache size seem to promise a low miss penalty and low cycles with a comparable hit rate; while a direct mapped cache showed comparable hit rates and miss penalties, though with lessr cache size, the miss penalties did reduce but cycles increased.

It can be said with regards to cache size that `lower cache size` lead to better miss penalty rates, with comparable hit rates.

Also, a fully associative cache shows a much better miss penalty than set-associative and direct-mapped caches. But this generalisation might fail with comparable cache sizes.

### For `1 256 64 write-allocate write-back lru`

    Total Loads : 318197

    Total Stores : 197486

    Load Hits : 314962

    Load Misses : 3235

    Store Hits : 194708

    Store Misses : 2778

    Total Cycles : 15275683

    `Hit Rate = 0.988`
    `Miss Penalty = 2540.443`

As proved above, fully associative cache with same cache size has a very high Hit Rate but a very Miss Penalty to pay too. So, m-way n-set associative achieves better results than direct mapped cache and fully associative cache.

So, the best performing cache is thus `m-way n-set associative cache with write-allocate write-back lru policy.`
