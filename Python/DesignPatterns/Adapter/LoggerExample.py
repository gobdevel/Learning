import sys
import syslog

from abc import ABC, abstractmethod


class Logger(ABC):

    @abstractmethod
    def log(self, message: str) -> None:
        pass


class FileLogger(Logger):
    """Logs to file"""

    def __init__(self, file) -> None:
        self._file = file

    def log(self, message) -> None:
        self._file.write(message + "\n")
        self._file.flush()


class SysLogger(Logger):
    """Logs to syslog"""

    def __init__(self, priority) -> None:
        self._priority = priority

    def log(self, message) -> None:
        syslog.syslog(self._priority, message)


class SocketLogger(Logger):
    """Logs to socket"""

    def __init__(self, sock) -> None:
        self._sock = sock

    def log(self, message) -> None:
        self._sock.sendall((message + "\n").encode("ascii"))


"""
    Till now all classes has single responsibility to send messages
    Now if we want to filter the messages
"""


# Adapter class which filter the messages then log based on
# what concerete logger is it holding (File, socker or syslog)
class FilteredLogger(Logger):
    """Filter the messages before logging"""

    def __init__(self, filter_text, logger):
        self._filter_text = filter_text
        self._concrete_logger = logger

    def log(self, message):
        if self._filter_text in message:
            self._concrete_logger.log(message)


if __name__ == "__main__":
    stdout_logger = FileLogger(sys.stdout)
    logger = FilteredLogger("hello", stdout_logger)
    logger.log("hello world")
    logger.log("nello world")
