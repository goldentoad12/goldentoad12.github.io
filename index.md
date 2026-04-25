---
layout: single
---

Welcome to my site!

<h2>Recent Projects</h2>

{% assign all_projects = site.projectsgis | concat: site.projectsarduino | sort: "date" | reverse %}

<ul>
  {% for project in all_projects limit: 5 %}
    <li>
      <a href="{{ project.url }}">{{ project.title }}</a><br>
      <small>{{ project.date | date: "%b %d, %Y" }}</small>
      <p>{{ project.excerpt }}</p>
    </li>
  {% endfor %}
</ul>
