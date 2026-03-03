import subprocess
import os
import re
import pytest

PROJECT_DIR = os.path.dirname(os.path.abspath(__file__))
ANALYZER = os.path.join(PROJECT_DIR, "analyzer")

def run_analyzer(*args):
    result = subprocess.run(
        [ANALYZER] + list(args),
        capture_output=True,
        text=True,
        timeout=5,
    )
    return result

def normalize(s):
    return re.sub(r"[^a-z0-9]", "", s.lower())

def output_contains(stdout, expected):
    return normalize(expected) in normalize(stdout)

class TestMainStructure:
    def test_usage_message(self):
        result = run_analyzer()
        assert result.returncode == 1
        assert "Usage: ./analyzer <mode> [arguments]" in result.stdout

    def test_invalid_mode(self):
        result = run_analyzer("invalid_mode_name")
        assert result.returncode == 1
        assert "Invalid mode" in result.stdout

class TestFunctionality:
    def test_text_mode(self):
        result = run_analyzer("text", "Hello 123!")
        out = result.stdout
        assert output_contains(out, "Letters 5")
        assert output_contains(out, "Digits 3")
        assert output_contains(out, "Punctuation 1")

    def test_add_mode_int(self):
        result = run_analyzer("add", "10", "20")
        assert output_contains(result.stdout, "Result 30")

    def test_add_mode_double(self):
        result = run_analyzer("add", "10.5", "20.5")
        assert output_contains(result.stdout, "Result 31")

    def test_stats_mode(self):
        result = run_analyzer("stats", "racecar")
        assert output_contains(result.stdout, "Palindrome Yes")
