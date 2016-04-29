#pragma once
#ifndef _GRAPH_SUBGRAPH_HPP
#define _GRAPH_SUBGRAPH_HPP

namespace graph {

/// An entire graph.
template<class T = std::size_t>
struct DefaultSubgraphMask {
    typedef T Value;

    bool vertex(const Value v) const
        { return true; }
    bool edge(const Value e) const
        { return true; }
};

} // namespace graph

#endif // #ifndef _GRAPH_SUBGRAPH_HPP
