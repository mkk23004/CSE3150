import subprocess
import pytest
from pathlib import Path

BASE_DIR = Path(__file__).parent
EXE_FILE = BASE_DIR / "solution.out"

def compile_program():
    # This matches the compilation command required for the assignment
    subprocess.check_call(
        f"g++ -std=c++17 {BASE_DIR}/solution.cpp -o {EXE_FILE}",
        shell=True
    )

def run_program(inputs: str, capacity: int = 100) -> str:
    compile_program()
    result = subprocess.run([str(EXE_FILE), str(capacity)], input=inputs.encode(), capture_output=True)
    return result.stdout.decode()

def test_add_and_print_student():
    output = run_program("1\nAlice\n3.5\n3\n5\n")
    assert "Alice" in output
    assert "3.5" in output

def test_update_gpa():
    output = run_program("1\nBob\n2.0\n2\n0\n3.7\n3\n5\n")
    assert "3.7" in output

def test_average_gpa():
    output = run_program("1\nA\n4.0\n1\nB\n2.0\n4\n5\n")
    assert "Average GPA" in output
    assert "3" in output  # average = 3.0

def test_no_students_average():
    output = run_program("4\n5\n")
    assert "Error: No students to average" in output
