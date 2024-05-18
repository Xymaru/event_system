#include <events/IEventListener.h>

#include <iostream>
#include <string>

struct LoggingEvent {
	std::string data;
};

struct LogErrorEvent {
	std::string data;
};

class DataLogger :
	public EM::IEventListener<LoggingEvent>,
	public EM::IEventListener<LogErrorEvent>
{
private:
	void debug_data(const std::string& data) {
		std::cout << data << std::endl;
	}
public:
	void OnEvent(const LoggingEvent& ev) override {
		debug_data(ev.data);
	}

	void OnEvent(const LogErrorEvent& ev) override {
		debug_data("Error: " + ev.data);
	}
};

int main() {
	DataLogger logger;

	LoggingEvent ev;
	ev.data = "HELLO WORLD!";

	EM::EventSystem::Trigger(ev);

	ev.data = "WOAAAAH!";

	EM::EventSystem::Trigger(ev);

	LogErrorEvent everror;
	everror.data = "Unknown :P";

	EM::EventSystem::Trigger(everror);

	return 0;
}