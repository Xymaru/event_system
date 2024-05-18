#include <events/IEventListener.h>

#include <iostream>
#include <string>

struct LoggingEvent {
	std::string data;
};

class DataLogger :
	public EM::IEventListener<LoggingEvent>
{
private:
	void debug_data(const std::string& data) {
		std::cout << data << std::endl;
	}
public:
	void OnEvent(const LoggingEvent& ev) override {
		debug_data(ev.data);
	}
};

int main() {
	DataLogger* logger = new DataLogger();

	LoggingEvent ev;
	ev.data = "HELLO WORLD!";

	EM::EventSystem::Trigger(ev);

	delete logger;

	ev.data = "WOAAAAH!";

	EM::EventSystem::Trigger(ev);

	return 0;
}