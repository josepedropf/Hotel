cmake_minimum_required(VERSION 3.17)
project(Hotel)

set(CMAKE_CXX_STANDARD 14)

add_executable(Hotel main.cpp Hotel.h Hotel.cpp Cliente.h Funcionario.h Reserva.h Quarto.h Produto.h Produto.cpp Reserva.cpp Quarto.cpp Funcionario.cpp Cliente.cpp Data.h Menu.cpp Menu.h Exceptions.cpp Exceptions.h Servico.cpp Servico.h Frota.cpp Frota.h)