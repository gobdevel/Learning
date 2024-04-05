# Adapter pattern concept

#In Python, the Adapter pattern is a structural design pattern that allows objects with incompatible interfaces to collaborate. Here’s a basic example:

'''
In this example:
  Target       : Defines the domain-specific interface that Client uses.
  Adaptee      : The class that has the incompatible interface, which needs
                 adaptation.
  Adapter      : Adapts the interface of Adaptee to the Target interface.
  client_code(): The client code that operates on objects conforming to the Target
                 interface.

When you run this script, it adapts the specific_request() method of Adaptee to the request() method of Target, allowing the client code to work seamlessly with Adaptee through the Adapter.


Usages :
1. In “proliferation of classes” and “explosion of subclasses” that the Gang of Four
   want to avoid.
2. Composition over inheritence
'''

class Target:
    """
    This is the target interface that the client expects to work with.
    """
    def request(self):
        return "Target: The default target's behavior."


class Adaptee:
    """
    This is the adaptee class which has a different interface that needs to be adapted.
    """
    def specific_request(self):
        return ".eetpadA eht fo roivaheb laicepS"


class Adapter(Target):
    """
    This is the adapter class which adapts the Adaptee interface to the Target interface.
    """
    def __init__(self, adaptee: Adaptee):
        self.adaptee = adaptee

    def request(self):
        return f"Adapter: (Translated) {self.adaptee.specific_request()[::-1]}"


def client_code(target: Target) -> None:
    """
    The client code works with objects that follow the Target interface.
    """
    print(target.request())


if __name__ == "__main__":
    adaptee = Adaptee()
    adapter = Adapter(adaptee)
    print("Client: The Adaptee class has a weird interface. "
          "See, I don't understand it:")
    print(f"Adaptee: {adaptee.specific_request()}")
    print("\n")
    print("Client: But I can work with it via the Adapter:")
    client_code(adapter)
