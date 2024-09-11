"""
Logger config
"""

import logging.config
import pathlib
import json
from typing import override

logger = logging.getLogger(__name__)  # __name__ is a common choice


def setup_logging():
    '''Setting up logger'''

    config_file = pathlib.Path(__file__).resolve().parent / "logger_conf.json"
    with open(config_file) as f_in:
        config = json.load(f_in)

    logging.config.dictConfig(config)
    # queue_handler = logging.getHandlerByName("queue_handler")
    # if queue_handler is not None:
    #     queue_handler.listener.start()
    #     atexit.register(queue_handler.listener.stop)


class NonErrorFilter(logging.Filter):
    @override
    def filter(self, record: logging.LogRecord) -> bool | logging.LogRecord:
        return record.levelno <= logging.INFO
