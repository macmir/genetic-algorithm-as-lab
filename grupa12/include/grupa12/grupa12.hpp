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

#ifndef GRUPA12__GRUPA12_HPP_
#define GRUPA12__GRUPA12_HPP_

#include <cstdint>

#include "grupa12/visibility_control.hpp"


namespace grupa12
{

class GRUPA12_PUBLIC Grupa12
{
public:
  Grupa12();
  int64_t foo(int64_t bar) const;
};

}  // namespace grupa12

#endif  // GRUPA12__GRUPA12_HPP_
