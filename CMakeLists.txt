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
        src/Fields/Property.cpp
        src/Fields/Field.h
        src/Fields/Field.cpp
        src/Fields/CardField.cpp
        src/Fields/CardField.h
        tests/TestCardField.cpp
        src/Fields/GoToJailField.cpp
        src/Fields/GoToJailField.h
        tests/TestGoToJailField.cpp
        tests/TestBoard.cpp
        src/Board.cpp
        src/Fields/TaxField.cpp
        src/Fields/TaxField.h
        tests/TestTaxField.cpp
        tests/TestUtilitiesField.cpp
        tests/TestTrainsField.cpp
        tests/TestField.cpp
        tests/TestPlayer.cpp
        src/Game.cpp
        src/Player.cpp
        src/Exceptions/BoardExceptions.cpp
        src/Exceptions/BoardExceptions.h
        tests/TestProperty.cpp
        src/Fields/Trains.cpp
        src/Fields/Trains.h
        src/Fields/OwnableField.cpp
        src/Fields/OwnableField.h
        src/Decision/DecisionSelector.cpp
        src/Decision/DecisionSelector.h
        src/Fields/Utilities.cpp
        tests/TestGamesScenarios.cpp
        src/Constants.h
        src/BoardSetupper.cpp
        src/BoardSetupper.h
        src/Decision/ConsoleDecisionSelector.cpp
        src/Decision/ConsoleDecisionSelector.h
        src/Decision/AiDecisionSelector.cpp
        src/Decision/AiDecisionSelector.h
        src/Decision/FieldVisitor.cpp
        src/Decision/FieldVisitor.h
        src/Decision/FieldBuyVisitor.cpp
        src/Decision/FieldBuyVisitor.h
        tests/TestGetFieldDecisions.cpp
        src/Card.cpp
        src/Card.h
        src/AdvanceToCard.cpp
        src/AdvanceToCard.h
)
target_link_libraries(MonopolyAITests gtest_main gtest gmock)
add_test(NAME MonopolyAITests COMMAND MonopolyAITests)

add_executable(MonopolyAI main.cpp
        src/Board.h
        src/Fields/Field.h
        src/Game.h
        src/Player.h
        src/Fields/Trains.h
        src/Fields/Utilities.h
        main.cpp
        src/Fields/Property.cpp
        src/Fields/Field.cpp
        src/Fields/CardField.cpp
        src/Fields/CardField.h
        src/Fields/GoToJailField.cpp
        src/Fields/GoToJailField.h
        src/Board.cpp
        src/Fields/TaxField.cpp
        src/Fields/TaxField.h
        src/Game.cpp
        src/Player.cpp
        src/Exceptions/BoardExceptions.cpp
        src/Exceptions/BoardExceptions.h
        src/Fields/Trains.cpp
        src/Fields/OwnableField.cpp
        src/Fields/OwnableField.h
        src/Decision/DecisionSelector.cpp
        src/Decision/DecisionSelector.h
        src/Fields/Utilities.cpp
        src/Constants.h
        src/BoardSetupper.cpp
        src/BoardSetupper.h
        src/Decision/ConsoleDecisionSelector.cpp
        src/Decision/ConsoleDecisionSelector.h
        src/Decision/AiDecisionSelector.cpp
        src/Decision/AiDecisionSelector.h
        src/Decision/FieldVisitor.cpp
        src/Decision/FieldVisitor.h
        src/Decision/FieldBuyVisitor.cpp
        src/Decision/FieldBuyVisitor.h
        src/Card.cpp
        src/Card.h
        src/AdvanceToCard.cpp
        src/AdvanceToCard.h
)