QT += core
QT -= gui

QMAKE_CXXFLAGS += -std=c++11
TARGET = garph_partition
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    kernigan_lin_unit.cpp

HEADERS += \
    include_files/random-access-set.hpp \
    include_files/partition.hpp \
    include_files/functional.hpp \
    include_files/graph/subgraph.hpp \
    include_files/graph/shortest-paths.hpp \
    include_files/graph/paths.hpp \
    include_files/graph/minimum-spanning-tree.hpp \
    include_files/graph/max-flow.hpp \
    include_files/graph/lifting.hpp \
    include_files/graph/grid-graph.hpp \
    include_files/graph/graph.hpp \
    include_files/graph/edge-value.hpp \
    include_files/graph/doxygen.hpp \
    include_files/graph/digraph.hpp \
    include_files/graph/dfs.hpp \
    include_files/graph/cut-vertices.hpp \
    include_files/graph/components.hpp \
    include_files/graph/complete-graph.hpp \
    include_files/graph/bridges.hpp \
    include_files/graph/bfs.hpp \
    include_files/graph/adjacency.hpp \
    include_files/graph/twocut-lifted/kernighan-lin.hpp \
    include_files/graph/twocut/kernighan-lin.hpp \
    include_files/graph/multicut-lifted/greedy-additive.hpp \
    include_files/graph/multicut-lifted/kernighan-lin.hpp \
    include_files/graph/multicut/greedy-additive.hpp \
    include_files/graph/multicut/greedy-fixation.hpp \
    include_files/graph/multicut/ilp.hpp \
    include_files/graph/multicut/kernighan-lin.hpp \
    include_files/graph/multicut/lp.hpp \
    include_files/graph/hdf5/complete-graph.hpp \
    include_files/graph/hdf5/digraph.hpp \
    include_files/graph/hdf5/graph.hpp \
    include_files/graph/hdf5/grid-graph.hpp \
    include_files/graph/hdf5/hdf5.hpp \
    include_files/graph/detail/graph.hpp \
    include_files/graph/visitor.hpp
    include_files/graph/visitor.hpp\
    #include_files/ilp/gurobi.h\
 #       include_files/lp/gurobi.hxx\

