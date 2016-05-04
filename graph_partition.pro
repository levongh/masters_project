#-------------------------------------------------
#
# Project created by QtCreator 2016-05-04T19:38:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++11
TEMPLATE = app
TARGET = garph_partition
SOURCES += main.cpp \
    kernigan_lin_unit.cpp \
    ui/edge.cpp \
    ui/node.cpp \
    ui/graphicsscene.cpp \
    ui/mainwindow.cpp \

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
    include_files/graph/visitor.hpp\
    ui/edge.h \
    ui/node.h \
    ui/graphicsscene.h \
    ui/mainwindow.h \

RESOURCES += \
    resources.qrc



