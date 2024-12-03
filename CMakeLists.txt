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
        src/Property.h
        src/Property.cpp
        src/Field.h
        src/Field.cpp
        src/CardField.cpp
        src/CardField.h
        tests/TestCardField.cpp
        src/GoToJailField.cpp
        src/GoToJailField.h
        tests/TestGoToJailField.cpp
        tests/TestBoard.cpp
        src/Board.cpp
        src/TaxField.cpp
        src/TaxField.h
        tests/TestTaxField.cpp
        tests/TestUtilitiesField.cpp
        tests/TestTrainsField.cpp
        tests/TestField.cpp
        tests/TestPlayer.cpp
        src/Game.cpp
        src/Player.cpp
        src/BoardExceptions.cpp
        src/BoardExceptions.h
        tests/TestProperty.cpp
        src/Trains.cpp
        src/Trains.h
        src/OwnableField.cpp
        src/OwnableField.h
        src/Decision/DecisionSelector.cpp
        src/Decision/DecisionSelector.h
        src/Utilities.cpp
        tests/TestGamesScenarios.cpp
        src/Constants.h
        src/BoardSetupper.cpp
        src/BoardSetupper.h
        src/Decision/ConsoleDecisionSelector.cpp
        src/Decision/ConsoleDecisionSelector.h
        src/Decision/AiDecisionSelector.cpp
        src/Decision/AiDecisionSelector.h
)
target_link_libraries(MonopolyAITests gtest_main)
add_test(NAME MonopolyAITests COMMAND MonopolyAITests)

add_executable(MonopolyAI main.cpp
        src/Board.h
        src/Field.h
        src/Game.h
        src/Player.h
        src/Trains.h
        src/Utilities.h
        main.cpp
        src/Property.cpp
        src/Field.cpp
        src/CardField.cpp
        src/CardField.h
        src/GoToJailField.cpp
        src/GoToJailField.h
        src/Board.cpp
        src/TaxField.cpp
        src/TaxField.h
        src/Game.cpp
        src/Player.cpp
        src/BoardExceptions.cpp
        src/BoardExceptions.h
        src/Trains.cpp
        src/OwnableField.cpp
        src/OwnableField.h
        src/Decision/DecisionSelector.cpp
        src/Decision/DecisionSelector.h
        src/Utilities.cpp
        src/Constants.h
        src/BoardSetupper.cpp
        src/BoardSetupper.h
        src/Decision/ConsoleDecisionSelector.cpp
        src/Decision/ConsoleDecisionSelector.h
        src/Decision/AiDecisionSelector.cpp
        src/Decision/AiDecisionSelector.h
)