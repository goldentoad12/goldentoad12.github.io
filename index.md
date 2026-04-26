--- 
layout: single 
header:
  image: /images/header.jpg

--- 

Welcome! This site will contain the following, an about me, my GIS and Arduino projects, my current academic publications, and an up to date resume. Use the navigation bar at the top of the screen to view everything. 

<h2>Recent Projects</h2> {% assign all_projects = site.projectsgis | concat: site.projectsarduino | sort: "date" | reverse %} <ul> {% for project in all_projects limit: 5 %} <li> <a href="{{ project.url }}">{{ project.title }}</a><br> <small>{{ project.date | date: "%b %d, %Y" }}</small> <p>{{ project.excerpt }}</p> </li> {% endfor %} </ul>
