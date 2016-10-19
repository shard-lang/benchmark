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
BENCHMARK_CAPTURE(Tokenize, identifiers, 	std::string("abcdefghijk_23 kjad abf_lab a5435_2a1 k32a"));
BENCHMARK_CAPTURE(Tokenize, integers, 		std::string("12345678910 123132485 4516411 3251156 2451"));
BENCHMARK_CAPTURE(Tokenize, floats, 		std::string("3.141592653589 3.14 3.1515 0003.14 3201.18"));
BENCHMARK_CAPTURE(Tokenize, floats_exp, 	std::string("1.45670e+25 1.23e-1 3.14E15 3.6E-8 3.215E2"));
BENCHMARK_CAPTURE(Tokenize, strings, 		std::string("\"1.45678\"\"abdadhj\"\"bdakb\"\"hbvdhsd\"\"abdjbj\""));
BENCHMARK_CAPTURE(Tokenize, chars, 			std::string("'a''b''c''d''e''f''g''h''i''j''k''l''m''n'"));
BENCHMARK_CAPTURE(Tokenize, others, 		std::string("{}[:](),.-+/#&^*<>=%;~?!),.-+/#&^{!),.}[:]"));

/* ************************************************************************* */

BENCHMARK_MAIN();

/* ************************************************************************* */