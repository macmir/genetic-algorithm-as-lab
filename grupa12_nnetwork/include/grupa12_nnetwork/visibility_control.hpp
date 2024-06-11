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

#ifndef GRUPA12_NNETWORK__VISIBILITY_CONTROL_HPP_
#define GRUPA12_NNETWORK__VISIBILITY_CONTROL_HPP_

////////////////////////////////////////////////////////////////////////////////
#if defined(__WIN32)
  #if defined(GRUPA12_NNETWORK_BUILDING_DLL) || defined(GRUPA12_NNETWORK_EXPORTS)
    #define GRUPA12_NNETWORK_PUBLIC __declspec(dllexport)
    #define GRUPA12_NNETWORK_LOCAL
  #else  // defined(GRUPA12_NNETWORK_BUILDING_DLL) || defined(GRUPA12_NNETWORK_EXPORTS)
    #define GRUPA12_NNETWORK_PUBLIC __declspec(dllimport)
    #define GRUPA12_NNETWORK_LOCAL
  #endif  // defined(GRUPA12_NNETWORK_BUILDING_DLL) || defined(GRUPA12_NNETWORK_EXPORTS)
#elif defined(__linux__)
  #define GRUPA12_NNETWORK_PUBLIC __attribute__((visibility("default")))
  #define GRUPA12_NNETWORK_LOCAL __attribute__((visibility("hidden")))
#elif defined(__APPLE__)
  #define GRUPA12_NNETWORK_PUBLIC __attribute__((visibility("default")))
  #define GRUPA12_NNETWORK_LOCAL __attribute__((visibility("hidden")))
#else
  #error "Unsupported Build Configuration"
#endif

#endif  // GRUPA12_NNETWORK__VISIBILITY_CONTROL_HPP_
