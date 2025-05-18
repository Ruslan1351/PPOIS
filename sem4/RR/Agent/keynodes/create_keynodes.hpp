#pragma once

#include <sc-memory/sc_keynodes.hpp>

class SearchKeynodes : public ScKeynodes
{ 
public:
  static inline ScKeynode const action_search_number_of_connected_components{"action_search_number_of_connected_components", ScType::NodeConstClass};
  static inline ScKeynode const nrel_number_of_connected_components{"nrel_number_of_connected_components", ScType::NodeConstNoRole};
};
