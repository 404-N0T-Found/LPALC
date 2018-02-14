QT += core
QT -= gui

TARGET = local-cycles-LPA
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    src/node.cpp \
    src/network.cpp \
    Sparse-Matrix/src/SparseMatrix/SparseMatrix.cpp \
    Sparse-Matrix/tests/run.cpp

HEADERS += \
    src/node.h \
    src/network.h \
    Sparse-Matrix/src/SparseMatrix/exceptions.h \
    Sparse-Matrix/src/SparseMatrix/SparseMatrix.h \
    Sparse-Matrix/tests/tests/addition.h \
    Sparse-Matrix/tests/tests/constructor.h \
    Sparse-Matrix/tests/tests/crs-format.h \
    Sparse-Matrix/tests/tests/custom-type.h \
    Sparse-Matrix/tests/tests/get-set.h \
    Sparse-Matrix/tests/tests/multiplication.h \
    Sparse-Matrix/tests/tests/output.h \
    Sparse-Matrix/tests/tests/subtraction.h \
    Sparse-Matrix/tests/SparseMatrixMock.h \
    Sparse-Matrix/tests/testslib.h

