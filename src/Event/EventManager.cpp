/**
 * This file is part of Rocky.
 *
 * Copyright (c) 2012, VolumetricPixels <http://www.volumetricpixels.com/>
 * Rocky is licensed under the GNU Lesser General Public License.
 *
 * Rocky is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Rocky is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <Event/EventManager.hpp>

boost::signals::connection& EventManager::addListener(std::string& eventName, EventSignal::slot_type& slot) {
	return events[eventName].connect(slot);
}

Event& EventManager::callEvent(std::string& eventName, Event& event) {
	events[eventName](event);
	return event;
}

EventSignal& EventManager::registerEvent(std::string& eventName) {
	events[eventName] = new EventSignal();
	return events[eventName];
}