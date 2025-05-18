#include "SearchNumberOfConnectedComponentsAgent.hpp"

#include "keynodes/search_keynodes.hpp"

ScAddr SearchNumberOfConnectedComponentsAgent::GetActionClass() const
{
  return SearchKeynodes::action_search_number_of_connected_components;
}

void SearchNumberOfConnectedComponentsAgent::DFS(ScAddr nodeAddr, std::vector<ScAddr>& visited) 
{
        std::stack<ScAddr> stack;
        stack.push(nodeAddr);
        while (!stack.empty()) {
            ScAddr currentNodeAddr = stack.top();
            stack.pop();
            if (std::find(visited.begin(), visited.end(), currentNodeAddr) == visited.end()) {
                visited.push_back(currentNodeAddr);  
                ScIterator3Ptr it3 = m_context.CreateIterator3(currentNodeAddr, ScType::EdgeUCommonConst, ScType::NodeConst);
                    while (it3->Next()) {
                        ScAddr const & neighbourNodeAddr = it3->Get(2);
                        if (std::find(visited.begin(), visited.end(), neighbourNodeAddr) == visited.end()) 
                            stack.push(neighbourNodeAddr);
                    }
            }
        }
}

ScResult SearchNumberOfConnectedComponentsAgent::DoProgram(ScAction & action)
{
  auto const & [graphAddr] = action.GetArguments<1>(); 
   if (!m_context.IsElement(graphAddr))
  {
    SC_AGENT_LOG_ERROR("Action does not have argument."); 
    return action.FinishWithError();
  }
  size_t number = 0;
  std::vector<ScAddr> visited;
  ScTemplate templ;
  templ.Triple(
    graphAddr,
    ScType::EdgeAccessVarPosPerm,
    ScType::NodeVar >> "_vertex"
  );
  ScTemplateSearchResult vertexes;
  m_context.SearchByTemplate(templ, vertexes);
  for (size_t i = 0; i < vertexes.Size(); i++) {
    ScTemplateResultItem vertex = vertexes[i];
    ScAddr const & vertexAddr = vertex["_vertex"];
    if (std::find(visited.begin(), visited.end(), vertexAddr) == visited.end()) {
      number++; 
      DFS(vertexAddr, visited);
    }
  }
  ScAddr const & linkAddr = m_context.GenerateLink(ScType::LinkConst);
  m_context.SetLinkContent(linkAddr, std::to_string(number));
  ScAddr const & arc1Addr = m_context.GenerateConnector(ScType::EdgeDCommonConst, graphAddr, linkAddr);
  ScAddr const & nrelNumberOfConnectedComponentsAddr = m_context.SearchElementBySystemIdentifier(SearchKeynodes::nrel_number_of_connected_components);
  ScAddr const & arc2Addr = m_context.GenerateConnector(ScType::EdgeAccessConstPosPerm, nrelNumberOfConnectedComponentsAddr, arc1Addr);
  action.FormResult(graphAddr, linkAddr, arc1Addr, nrelNumberOfConnectedComponentsAddr, arc2Addr);
  return action.FinishSuccessfully();
} 