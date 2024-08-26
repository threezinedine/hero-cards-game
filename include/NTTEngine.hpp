#pragma once

#include <cores/core.hpp>
#include <utils/utils.hpp>

ntt::Ref<ntt::Application> CreateApplication(ntt::ConfigurableObject &config);
ntt::String GetCofigPath();