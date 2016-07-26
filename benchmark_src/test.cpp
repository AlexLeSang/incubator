// #include <benchmark/benchmark_api.h>
// #include <string>
// #include <cstring>

// static void BM_StringCreation(benchmark::State& state) {
//   while (state.KeepRunning())
//     std::string empty_string;
// }
// // Register the function as a benchmark
// BENCHMARK(BM_StringCreation);

// // Define another benchmark
// static void BM_StringCopy(benchmark::State& state) {
//   std::string x = "hello";
//   while (state.KeepRunning())
//     std::string copy(x);
// }
// BENCHMARK(BM_StringCopy);

// static void BM_memcpy(benchmark::State& state) {
//   char* src = new char[state.range_x()];
//   char* dst = new char[state.range_x()];
//   memset(src, 'x', state.range_x());
//   while (state.KeepRunning())
//     memcpy(dst, src, state.range_x());
//   state.SetBytesProcessed(int64_t(state.iterations()) * int64_t(state.range_x()));
//   delete[] src;
//   delete[] dst;
//   std::string s;
// }
// BENCHMARK(BM_memcpy)->Arg(8)->Arg(64)->Arg(512)->Arg(1<<10)->Arg(8<<10)->Arg(16<<10)->Arg(32<<10)->Arg(64<<10);

// BENCHMARK_MAIN();
