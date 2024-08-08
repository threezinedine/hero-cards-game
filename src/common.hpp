#pragma once

#include <memory>
#include <vector>
#include <utility>
#include <random>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <raylib.h>
#include <nlohmann/json.hpp>
#include <type_traits>

template <typename T>
using Scope = std::unique_ptr<T>;

template <typename T>
using Ref = std::shared_ptr<T>;

template <typename T, typename... Args>
Scope<T> CreateScope(Args &&...args)
{
    return std::make_unique<T>(std::forward<Args>(args)...);
}

template <typename T, typename... Args>
Ref<T> CreateRef(Args &&...args)
{
    return std::make_shared<T>(std::forward<Args>(args)...);
}

template <typename T>
using List = std::vector<T>;

template <typename T, typename U>
using Pair = std::pair<T, U>;

using String = std::string;

template <typename T, typename U>
using Map = std::unordered_map<T, U>;

using JSON = nlohmann::json;