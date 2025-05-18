#include "searchNumberOfConnectedComponentsModule.hpp"

#include "agent/SearchNumberOfConnectedComponentsAgent.hpp"

SC_MODULE_REGISTER(SearchNumberOfConnectedComponentsModule)
  ->Agent<SearchNumberOfConnectedComponentsAgent>();