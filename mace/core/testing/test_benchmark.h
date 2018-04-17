// Copyright 2018 Xiaomi, Inc.  All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Simple benchmarking facility.
#ifndef MACE_CORE_TESTING_TEST_BENCHMARK_H_
#define MACE_CORE_TESTING_TEST_BENCHMARK_H_

#include <string>
#include <utility>
#include <vector>

#define MACE_BENCHMARK_CONCAT(a, b, c) a##b##c
#define BENCHMARK(n)                                        \
  static ::mace::testing::Benchmark *MACE_BENCHMARK_CONCAT( \
      __benchmark_, n, __LINE__) = (new ::mace::testing::Benchmark(#n, (n)))

namespace mace {
namespace testing {

class Benchmark {
 public:
  Benchmark(const char *name, void (*benchmark_func)(int));

  static void Run();
  static void Run(const char *pattern);

 private:
  std::string name_;
  void (*benchmark_func_)(int iters) = nullptr;

  void Register();
  void Run(int *run_count, double *run_seconds);
};

void BytesProcessed(int64_t);
void MaccProcessed(int64_t);
void RestartTiming();
void StartTiming();
void StopTiming();

}  // namespace testing
}  // namespace mace

#endif  // MACE_CORE_TESTING_TEST_BENCHMARK_H_
