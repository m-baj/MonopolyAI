cmake_minimum_required(VERSION 3.29)
project(MonopolyAI)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(MonopolyAITests
        src/Fields/Property.h
        src/Fields/Property.cc
        src/Fields/Field.h
        src/Fields/Field.cc
        src/Fields/CardField.cc
        src/Fields/CardField.h
        tests/TestCardField.cpp
        src/Fields/GoToJailField.cc
        src/Fields/GoToJailField.h
        tests/TestGoToJailField.cpp
        tests/TestBoard.cpp
        src/Board.cc
        src/Fields/TaxField.cc
        src/Fields/TaxField.h
        tests/TestTaxField.cpp
        tests/TestUtilitiesField.cpp
        tests/TestTrainsField.cpp
        tests/TestField.cpp
        tests/TestPlayer.cpp
        src/Game.cc
        src/Player.cc
        src/Exceptions/BoardExceptions.cc
        src/Exceptions/BoardExceptions.h
        tests/TestProperty.cpp
        src/Fields/Trains.cc
        src/Fields/Trains.h
        src/Fields/OwnableField.cc
        src/Fields/OwnableField.h
        src/Decision/DecisionSelector.cc
        src/Decision/DecisionSelector.h
        src/Fields/Utilities.cc
        tests/TestGamesScenarios.cpp
        src/Constants.h
        src/BoardSetupper.cc
        src/BoardSetupper.h
        src/Decision/ConsoleDecisionSelector.cc
        src/Decision/ConsoleDecisionSelector.h
        src/Decision/AiDecisionSelector.cc
        src/Decision/AiDecisionSelector.h
)
target_link_libraries(MonopolyAITests gtest_main)
add_test(NAME MonopolyAITests COMMAND MonopolyAITests)

add_executable(MonopolyAI main.cc
        src/Board.h
        src/Fields/Field.h
        src/Game.h
        src/Player.h
        src/Fields/Trains.h
        src/Fields/Utilities.h
        main.cc
        src/Fields/Property.cc
        src/Fields/Field.cc
        src/Fields/CardField.cc
        src/Fields/CardField.h
        src/Fields/GoToJailField.cc
        src/Fields/GoToJailField.h
        src/Board.cc
        src/Fields/TaxField.cc
        src/Fields/TaxField.h
        src/Game.cc
        src/Player.cc
        src/Exceptions/BoardExceptions.cc
        src/Exceptions/BoardExceptions.h
        src/Fields/Trains.cc
        src/Fields/OwnableField.cc
        src/Fields/OwnableField.h
        src/Decision/DecisionSelector.cc
        src/Decision/DecisionSelector.h
        src/Fields/Utilities.cc
        src/Constants.h
        src/BoardSetupper.cc
        src/BoardSetupper.h
        src/Decision/ConsoleDecisionSelector.cc
        src/Decision/ConsoleDecisionSelector.h
        src/Decision/AiDecisionSelector.cc
        src/Decision/AiDecisionSelector.h
)