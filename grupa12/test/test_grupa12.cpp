// Copyright 2024 111
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "gtest/gtest.h"
#include "grupa12/grupa12.hpp"

TEST(TestGrupa12, TestHello) {
  std::unique_ptr<grupa12::Grupa12> grupa12_ =
    std::make_unique<grupa12::Grupa12>();
  auto result = grupa12_->foo(999);
  EXPECT_EQ(result, 999);
}
