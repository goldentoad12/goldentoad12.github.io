--- 
layout: single
header:
  image: /images/header.jpg
  show_overlay_excerpt: true
  excerpt: "My goal is to turn environmental data into actionable insight for climate resilience and sustainable systems."
--- 

Welcome! This site will contain the following, an about me, my GIS and Arduino projects, my current academic publications, and an up to date resume. Use the navigation bar at the top of the screen to view everything. 

<h2>Recent Projects</h2>

{% assign all_projects = site.projectsgis | concat: site.projectsarduino | sort: "date" | reverse %}

<div class="project-gallery">
  {% for project in all_projects limit: 5 %}
  <a class="project-tile" href="{{ project.url }}">
    <div class="project-tile-content">
      <h3>{{ project.title }}</h3>
      <small>{{ project.date | date: "%b %d, %Y" }}</small>
      <p>{{ project.excerpt }}</p>
    </div>
  </a>
  {% endfor %}
</div>
