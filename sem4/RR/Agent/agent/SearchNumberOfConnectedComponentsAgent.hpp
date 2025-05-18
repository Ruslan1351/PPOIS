#pragma once

#include <sc-memory/sc_memory.hpp>
#include <sc-memory/sc_agent.hpp>

class SearchNumberOfConnectedComponentsAgent : public ScActionInitiatedAgent
{
public:
  ScAddr GetActionClass() const override;
  
  void DFS(ScAddr nodeAddr, std::vector<ScAddr>& visited);
  
  ScResult DoProgram(ScAction & action) override;
};
