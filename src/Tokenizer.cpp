/* ************************************************************************* */
/* This file is part of Shard.                                               */
/*                                                                           */
/* Shard is free software: you can redistribute it and/or modify             */
/* it under the terms of the GNU Affero General Public License as            */
/* published by the Free Software Foundation.                                */
/*                                                                           */
/* This program is distributed in the hope that it will be useful,           */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of            */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the              */
/* GNU Affero General Public License for more details.                       */
/*                                                                           */
/* You should have received a copy of the GNU Affero General Public License  */
/* along with this program. If not, see <http://www.gnu.org/licenses/>.      */
/* ************************************************************************* */

// C++
#include <string>

// Google benchmark
#include "benchmark/benchmark.h"

// Shard
#include "shard/tokenizer/Tokenizer.hpp"

/* ************************************************************************* */

static void Tokenize(benchmark::State& state, std::string src)
{
    while (state.KeepRunning())
    {
        shard::tokenizer::Tokenizer tokenizer(src);
        for (auto&& token : tokenizer)
          benchmark::DoNotOptimize(token);
    }
}

/* ************************************************************************* */

// Sources
BENCHMARK_CAPTURE(Tokenize, identifier, std::string("abcd"));
BENCHMARK_CAPTURE(Tokenize, integer, std::string("12345678910"));
BENCHMARK_CAPTURE(Tokenize, float, std::string("0.45678E12345"));

/* ************************************************************************* */

BENCHMARK_MAIN();

/* ************************************************************************* */